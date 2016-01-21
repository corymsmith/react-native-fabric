/**
 * @providesModule Crashlytics
 */
'use strict';

var { NativeModules, Platform } = require('react-native');
var SMXCrashlytics = NativeModules.SMXCrashlytics;

module.exports = {

  log: function (message:string) {
    SMXCrashlytics.log(message);
  },

  setUserEmail: function (email:string) {
    SMXCrashlytics.setUserEmail(email);
  },

  setUserIdentifier: function (userIdentifier) {
    SMXCrashlytics.setUserIdentifier(userIdentifier);
  },

  setUserName: function (userName:string) {
    SMXCrashlytics.setUserName(userName);
  },

  setBool: function (key:string, value:boolean) {
    SMXCrashlytics.setBool(key, value);
  },

  setNumber: function (key:string, value:number) {
    // This is a hack but allows us to have a standard API for both platforms
    if (Platform.OS === 'android') {
      value = value + "";
    }
    SMXCrashlytics.setNumber(key, value);
  },

  setString: function (key:string, value:string) {
    SMXCrashlytics.setString(key, value);
  }
};
