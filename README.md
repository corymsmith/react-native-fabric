# react-native-fabric
A React Native library for Fabric, Crashlytics and Answers

This is a work in progress and has yet to be published to NPM 

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


// Due to differences in primitive types between iOS and Android I've exposed a setNumber function vs. setInt, setFloat, setDouble, setLong, etc                                        
Crashlytics.setNumber('post_count', 5);

```

## Answers Usage
To see all available methods take a look at [Answers.js](https://github.com/corymsmith/react-native-fabric/blob/master/Answers.js)
```js
var Fabric = require('react-native-fabric');

var { Answers } = Fabric;
Answers.logCustom('Performed a custom event', { bigData: true });

``` 


## Todo

- [x] Crashlytics logging / custom keys 
- [ ] Answers for iOS
- [ ] Answers for Android
- Publish to NPM

## License
MIT © Cory Smith 2016
