# react-native-fabric
A React Native library for Fabric, Crashlytics and Answers

## Installation

`npm install react-native-fabric`

- Set up Fabric / Crashlytics in your app as instructed on [Fabric.io](https://fabric.io)

- Alternatively if you don't use Android studio you also need to follow the steps described in 'Android without Android Studio' **as well as** the steps in 'Android'.

### iOS
 
- Open your project in Xcode
- Run ```open node_modules/react-native-fabric/ios```
- Drag `SMXCrashlytics.xcodeproj` into your `Libraries` group
- Select your main project in the navigator to bring up settings
- Under `Build Phases` expand the `Link Binary With Libraries` header
- Scroll down and click the `+` to add a library
- Find and add `libSMXCrashlytics.a` under the `Workspace` group
- ⌘+B

### Android

*Note: Android support requires React Native 0.16 or later 

* Edit `android/settings.gradle` to look like this (without the +):

  ```diff
  rootProject.name = 'MyApp'

  include ':app'

  + include ':react-native-fabric'
  + project(':react-native-fabric').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-fabric/android')
  ```

* Edit `android/app/build.gradle` (note: **app** folder) to look like this: 

  ```diff
  apply plugin: 'com.android.application'

  android {
    ...
  }

  dependencies {    
    compile 'com.android.support:appcompat-v7:23.0.0'
    compile 'com.facebook.react:react-native:0.19.+'
  + compile project(':react-native-fabric')
  }
  ```

* Edit your `MainActivity.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
  package com.myapp;

  + import com.smixx.fabric.FabricPackage;

  ....

  public class MainActivity extends Activity implements DefaultHardwareBackBtnHandler {

    private ReactInstanceManager mReactInstanceManager;
    private ReactRootView mReactRootView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      mReactRootView = new ReactRootView(this);

      mReactInstanceManager = ReactInstanceManager.builder()
        .setApplication(getApplication())
        .setBundleAssetName("index.android.bundle")
        .setJSMainModuleName("index.android")
        .addPackage(new MainReactPackage())
  +     .addPackage(new FabricPackage(this))
        .setUseDeveloperSupport(BuildConfig.DEBUG)
        .setInitialLifecycleState(LifecycleState.RESUMED)
        .build();

      mReactRootView.startReactApplication(mReactInstanceManager, "MyApp", null);

      setContentView(mReactRootView);
    }
    ...
  }
  ```

### Android without Android Studio

Make sure you also follow the steps described in the previous section 'Android'.

* Edit your `build.gradle` (note: **app** folder) to look like this.

```
  apply plugin: "com.android.application"

  + buildscript {
  +   repositories {
  +     maven { url 'https://maven.fabric.io/public' }
  +   }
  +   dependencies {
  +     // The Fabric Gradle plugin uses an open ended version to react
  +     // quickly to Android tooling updates
  +     classpath 'io.fabric.tools:gradle:1.+'
  +   }
  + }
  + apply plugin: 'io.fabric'
  + repositories {
  +   maven { url 'https://maven.fabric.io/public' }
  + }

  [...]

  dependencies {
      [...]
  +     compile('com.crashlytics.sdk.android:crashlytics:2.5.5@aar') {
  +         transitive = true;
  +     }
  }
```

* Edit your `MainActivity.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

```
  + import android.os.Bundle;
  + import com.crashlytics.android.Crashlytics;
  + import io.fabric.sdk.android.Fabric;

  public class MainActivity extends ReactActivity {

  +   @Override
  +   protected void onCreate(Bundle savedInstanceState) {
  +       super.onCreate(savedInstanceState);
  +       Fabric.with(this, new Crashlytics());
  +   }

    [...]

  }

```

* Edit your `AndroidManifest.xml` (in `android/app/src/main/`) to look like this. Make sure to enter your fabric API key after `android:value=`, you can find your key on your fabric organisation page.

```
  <manifest xmlns:android="http://schemas.android.com/apk/res/android"
      [...]
      <application
        [...]
  +       <meta-data
  +         android:name="io.fabric.ApiKey"
  +         android:value=[YOUR API KEY]
  +       />
      </application>
  +   <uses-permission android:name="android.permission.INTERNET" />
  </manifest>
```

## Crashlytics Usage
To see all available methods take a look at [Crashlytics.js](https://github.com/corymsmith/react-native-fabric/blob/master/Crashlytics.js)

```js
var Fabric = require('react-native-fabric');

var { Crashlytics } = Fabric;

Crashlytics.setUserName('megaman');

Crashlytics.setUserEmail('user@email.com');

Crashlytics.setUserIdentifier('1234');

Crashlytics.setBool('has_posted', true);

Crashlytics.setString('organization', 'Acme. Corp');

// Forces a native crash for testing
Crashlytics.crash();

// Record a non-fatal JS error
Crashlytics.recordError('something went wrong!');

// Due to differences in primitive types between iOS and Android I've exposed a setNumber function vs. setInt, setFloat, setDouble, setLong, etc                                        
Crashlytics.setNumber('post_count', 5);

// Record a non-fatal JS error on Android
Crashlytics.logException('');

```

## Answers Usage
To see all available function take a look at [Answers.js](https://github.com/corymsmith/react-native-fabric/blob/master/Answers.js)

```js
var Fabric = require('react-native-fabric');

var { Answers } = Fabric;

// All log functions take an optional array of custom attributes as the last parameter
Answers.logCustom('Performed a custom event', { bigData: true });

Answers.logAddToCart(24.50, 'USD', 'Air Jordans', 'shoes', '987654', {color: 'red'});

Answers.logInvite('Facebook');

Answers.logLogin('Twitter', true);

Answers.logSearch('React Native');

Answers.logShare('Twitter', 'Big news article', 'post', '1234');

Answers.logSignUp('Twitter', true);

Answers.logPurchase(24.99,'USD',true, 'Air Jordans', 'shoes', '987654');


``` 


## License
MIT © Cory Smith 2016
