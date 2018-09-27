# react-native-fabric
A React Native library for Fabric, Crashlytics and Answers

[![NPM](https://nodei.co/npm/react-native-fabric.png?downloads=true&downloadRank=true&stars=true)](https://nodei.co/npm/react-native-fabric/)


## Versioning
- For React Native > 0.40 use version 0.5.1
- For React Native < 0.40 use version 0.3.2

For Twitter Kit support, see [react-native-fabric-twitterkit](https://github.com/tkporter/react-native-fabric-twitterkit)

## Installation

### 1. Add Fabric / Crashlytics to your project

- First, set up Fabric / Crashlytics in your app as instructed on [Fabric.io](https://fabric.io).  This includes downloading the fabric app and walking through the setup steps (downloading the SDK, adding it to your project and making some changes to your project).

### 2. Add react-native-fabric

#### Automatically

`react-native install react-native-fabric`, or with [rnpm](https://github.com/rnpm/rnpm): `rnpm install react-native-fabric`

React Native / rnpm will automatically link all the necessary libraries for both iOS and Android.

If the installation goes off without a hitch, you can now skip to the **[Crashlytics Usage section](#crashlytics-usage)** or the **[Answers Usage section](#answers-usage)**.

#### Manually

`npm install react-native-fabric --save`

- Alternatively for Android, if you **don't** use Android studio you can skip the first step and instead follow the steps described in [`Android`](#android) **as well as** the steps in [`Android without Android Studio`](#no_android_studio).

##### Manually iOS With CocoaPods support

- add the following line to Podfile

`pod 'ReactNativeFabric', :path => '../node_modules/react-native-fabric'`

##### Manually iOS Without CocoaPods support

Download the [Crashlytics
SDK](https://fabric.io/kits/ios/crashlytics/manual-install) and place the two
frameworks in a directory called `Crashlytics` in the `ios` directory. You may
want to add this directory to your `.gitignore` as they take up a decent amount
of space and will slow down Git.

You will also need to modify the Run Script Phase that you likely added to Build
Phases so that it points to the correct location for the Fabric framework. If
you placed the framework directly under `ios/Crashlytics` as specified above,t
the contents of the script will then be:

```
"${SRCROOT}/Crashlytics/Fabric.framework/run" API_KEY API_SECRET
```

Then do the following:

- Open your project in Xcode
- Run ```open node_modules/react-native-fabric/ios```
- Drag `SMXCrashlytics.xcodeproj` into your `Libraries` group
- Select your main project in the navigator to bring up settings
- Under `Build Phases` expand the `Link Binary With Libraries` header
- Scroll down and click the `+` to add a library
- Find and add `libSMXCrashlytics.a` under the `Workspace` group
- ⌘+B

<a name="android"></a>
##### Android

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

* RN < 0.29 - Edit your `MainActivity.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
  package com.myapp;

  + import com.smixx.fabric.FabricPackage;

  ....
  public class MainActivity extends ReactActivity {
    @Override
    protected List<ReactPackage> getPackages() {
        return Arrays.<ReactPackage>asList(
  +         new FabricPackage(),
            new MainReactPackage()
        );
    }
  }
  ```

* RN 0.29+ - Edit your `MainApplication.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
  package com.myapp;

  + import com.smixx.fabric.FabricPackage;

  ....
  public class MainApplication extends Application implements ReactApplication {
    @Override
    protected List<ReactPackage> getPackages() {
        return Arrays.<ReactPackage>asList(
  +         new FabricPackage(),
            new MainReactPackage()
        );
    }
  }
  ```  

<a name="no_android_studio"></a>
##### Android without Android Studio

Make sure you also follow the steps described in [`Android`](#android).

* Edit your `build.gradle` (note: **app** folder) to look like this:

  ```diff
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
  +     compile('com.crashlytics.sdk.android:crashlytics:2.9.2@aar') {
  +         transitive = true;
  +     }
  }
  ```

* RN < 0.29 - Edit your `MainActivity.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
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

* RN 0.29+ - Edit your `MainApplication.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
  + import com.crashlytics.android.Crashlytics;
  + import io.fabric.sdk.android.Fabric;
  
  public class MainApplication extends Application implements ReactApplication {
  
  +   @Override
  +   public void onCreate() {
  +       super.onCreate();
  +       Fabric.with(this, new Crashlytics());
  +   }
  
    [...]
  
  }
  ``` 

* Note: the `onCreate` access privilege goes from `protected` to `public` from RN 0.28+

* Edit your `AndroidManifest.xml` (in `android/app/src/main/`) to look like this. Make sure to enter your fabric API key after `android:value=`, you can find your key on your fabric organisation page.

  ```diff
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

**Note: logging will not be registered on Android to the Fabric dashboard until the app is bundled for release.**

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

// Due to differences in primitive types between iOS and Android I've exposed a setNumber function vs. setInt, setFloat, setDouble, setLong, etc                                        
Crashlytics.setNumber('post_count', 5);

// Record a non-fatal JS error only on Android
Crashlytics.logException('');

// Record a non-fatal JS error only on iOS
Crashlytics.recordError('something went wrong!');

```

## Answers Usage
To see all available function take a look at [Answers.js](https://github.com/corymsmith/react-native-fabric/blob/master/Answers.js)

```js
var Fabric = require('react-native-fabric');

var { Answers } = Fabric;

// All log functions take an optional object of custom attributes as the last parameter
Answers.logCustom('Performed a custom event', { bigData: true });

Answers.logContentView('To-Do Edit', 'To-Do', 'to-do-42', { userId: 93 });

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


[rnpm]: https://github.com/rnpm/rnpm
