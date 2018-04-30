/**
 * @providesModule Crashlytics
 */
// @flow

import { NativeModules, Platform } from 'react-native'
const SMXCrashlytics = NativeModules.SMXCrashlytics

export const Crashlytics = {
  crash: SMXCrashlytics.crash,
  throwException: SMXCrashlytics.throwException,

  /**
   * Convert error into something the native code knows what to do with.
   * Attempts to be flexible and accept error objects in different formats.
   * We need to be careful which data types we send to the native layer.
   * Could do something much fancier here, e.g., deep, recursive serialization
   * (or "flattening") but keep it simple for now.
   * @param error
   */
  recordError: function(error: mixed) {
    var newError

    if (typeof error === 'string' || error instanceof String) {
      newError = { domain: error }
    } else if (typeof error === 'number') {
      newError = { code: error }
    } else if (typeof error === 'object') {
      newError = {}

      // Pass everything in as a string or number to be safe
      for (var k in error) {
        if (error.hasOwnProperty(k)) {
          if (
            typeof error[k] !== 'number' &&
            typeof error[k] !== 'string' &&
            !(error[k] instanceof String)
          ) {
            newError[k] = JSON.stringify(error[k])
          } else {
            newError[k] = error[k]
          }
        }
      }
    } else {
      // Array?
      // Fall back on JSON
      newError = {
        json: JSON.stringify(error),
      }
    }
    SMXCrashlytics.recordError(newError)
  },

  logException: function(value: string) {
    SMXCrashlytics.logException(value)
  },

  log: function(message: string) {
    SMXCrashlytics.log(message)
  },

  setUserEmail: function(email: string | null) {
    SMXCrashlytics.setUserEmail(email)
  },

  setUserIdentifier: function(userIdentifier: string | null) {
    SMXCrashlytics.setUserIdentifier(userIdentifier)
  },

  setUserName: function(userName: string | null) {
    SMXCrashlytics.setUserName(userName)
  },

  setBool: function(key: string, value: boolean) {
    SMXCrashlytics.setBool(key, value)
  },

  setNumber: function(key: string, value: number) {
    // This is a hack but allows us to have a standard API for both platforms
    if (Platform.OS === 'android') SMXCrashlytics.setNumber(key, value + '')
    else SMXCrashlytics.setNumber(key, value)
  },

  setString: function(key: string, value: string) {
    SMXCrashlytics.setString(key, value)
  },

  recordCustomExceptionName: function(
    name: string,
    reason: string,
    stack?: Object[]
  ) {
    SMXCrashlytics.recordCustomExceptionName(name, reason, stack || [])
  },
}
