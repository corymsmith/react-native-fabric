/**
 * @providesModule Fabric
 */
'use strict';

var { NativeModules } = require('react-native');
var SMXCrashlytics = NativeModules.SMXCrashlytics;

var Crashlytics = {

  setUserEmail: function (email:string) {
    SMXCrashlytics.setUserEmail(email);
  },

  setUserIdentifier: function (userIdentifier: string) {
    SMXCrashlytics.setUserIdentifier(userIdentifier);
  },

  setUserName: function (userName:string) {
    SMXCrashlytics.setUserName(userName);
  },

  setBool: function (key:string, value:boolean) {
    SMXCrashlytics.setBool(key, value);
  },

  setDouble: function (key:string, value:number) {
    SMXCrashlytics.setDouble(key, value);
  },

  setFloat: function (key:string, value:number) {
    SMXCrashlytics.setFloat(key, value);
  },

  setLong: function (key:string, value:number) {
    SMXCrashlytics.setLong(key, value);
  },

  setString: function (key:string, value:string) {
    SMXCrashlytics.setString(key, value);
  },

  setInt: function (key:string, value:number) {
    SMXCrashlytics.setInt(key, value);
  },
  setObject: function(key:string, value) {
    //TODO: Doesn't exist on Android
  }
};

module.exports.Crashlytics = Crashlytics;