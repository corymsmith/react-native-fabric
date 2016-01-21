/**
 * @providesModule Crashlytics
 */
'use strict';

var { NativeModules } = require('react-native');
var SMXCrashlytics = NativeModules.SMXCrashlytics;

module.exports = {

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
    SMXCrashlytics.setNumber(key, value);
  },

  setString: function (key:string, value:string) {
    SMXCrashlytics.setString(key, value);
  }
};
