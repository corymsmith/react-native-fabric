# react-native-fabric
A React Native library for Fabric, Crashlytics and Answers

This is a work in progress and has yet to be published to NPM 

## Installation

`$ npm install react-native-fabric`

### Option: Manually

* Right click on Libraries, select **Add files to "…"** and select `node_modules/react-native-fabric/RNFabric.xcodeproj`
* Select your project and under **Build Phases** -> **Link Binary With Libraries**, press the + and select `libRNFabric.a`.

```

## Usage

```js
var Crashlytics = require('react-native-fabric').Crashlytics;

Crashlytics.setUserEmail('user@email.com');


```

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
    compile fileTree(dir: 'libs', include: ['*.jar'])
    compile 'com.android.support:appcompat-v7:23.0.0'
    compile 'com.facebook.react:react-native:0.16.+'
  + compile project(':react-native-fabric')
  }
  ```

* Edit your `MainActivity.java` (deep in `android/app/src/main/java/...`) to look like this (note **two** places to edit):

  ```diff
  package com.myapp;

  + import com.smixxtape.reactnativefabric.ReactNativeFabric;

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
  +     .addPackage(new ReactNativeFabric(this))
        .setUseDeveloperSupport(BuildConfig.DEBUG)
        .setInitialLifecycleState(LifecycleState.RESUMED)
        .build();

      mReactRootView.startReactApplication(mReactInstanceManager, "MyApp", null);

      setContentView(mReactRootView);
    }
    ...
  }
  ```

## Todo

- [ ] Crashlytics logging / custom keys 
- [ ] Answers for iOS
- [ ] Answers for Android

## License
MIT © Cory Smith 2016
