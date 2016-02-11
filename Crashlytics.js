/**
 * @providesModule Crashlytics
 */
'use strict';

var { NativeModules, Platform } = require('react-native');
var SMXCrashlytics = NativeModules.SMXCrashlytics;

module.exports = {

  crash: SMXCrashlytics.crash,
  throwException: SMXCrashlytics.throwException,

  recordError: function (error) {
    var newError;

    /**
     * We need to be careful which data types we send to the native layer.
     * Could do something much fancier here, e.g., deep, recursive serialization
     * but keep it simple for now.
     */
    if (typeof error === "string" || error instanceof String) {
      newError = {message: error};
    }
    else if (typeof error === "number") {
      newError = {code: error};
    }
    else if (typeof error === "Object") {
      newError = {};

      // Pass everything in as a string or number to be safe
      for (var k in error) {
        if (error.hasOwnProperty(k)) {
          if ((typeof error[k] !== "number") && (typeof (error[k] !== "string")) && !(error[k] instanceof String)) {
            newError[k] = JSON.stringify(error[k]);
          }
          else {
            newError[k] = error[k]
          }
        }
      }
    }
    else {
      // Array?
      // Fall back on JSON
      newError = {
        json: JSON.stringify(error);
      }
    }
    SMXCrashlytics.recordError(newError);
  },

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
