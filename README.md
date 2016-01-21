# react-native-fabric
A React Native library for Fabric, Crashlytics and Answers

This is a work in progress and has yet to be published to NPM 

## Crashlytics Usage

```js
var Fabric = require('react-native-fabric');

var { Crashlytics } = Fabric;

Crashlytics.setUserName('megaman');

Crashlytics.setUserEmail('user@email.com');

Crashlytics.setUserIdentifier('1234');

Crashlytics.setBool('has_posted', true);

Crashlytics.setNumber('post_count', 5);

Crashlytics.setString('organization', 'Acme. Corp');


```

## Answers Usage
```js
var Fabric = require('react-native-fabric');

var { Answers } = Fabric;
Answers.logCustom('Performed a custom event', { bigData: true });
 


## Todo

- [x] Crashlytics logging / custom keys 
- [ ] Answers for iOS
- [ ] Answers for Android
- Publish to NPM

## License
MIT © Cory Smith 2016
