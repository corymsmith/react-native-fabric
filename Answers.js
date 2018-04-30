/**
 * @providesModule Answers
 */
// @flow

import { NativeModules, Platform } from 'react-native'
const SMXAnswers = NativeModules.SMXAnswers

function getAsStringOrNull(value: number): string {
  if (value == null) return value
  return value + ''
}

export const Answers = {
  logCustom: function(eventName: string, customAttributes?: Object) {
    SMXAnswers.logCustom(eventName, customAttributes)
  },
  logAddToCart: function(
    itemPrice: number,
    currency: string,
    itemName: string,
    itemType: string,
    itemId: string,
    customAttributes?: Object
  ) {
    SMXAnswers.logAddToCart(
      getAsStringOrNull(itemPrice),
      currency,
      itemName,
      itemType,
      itemId,
      customAttributes
    )
  },

  logContentView: function(
    contentName: string,
    contentType?: string,
    contentId?: string,
    customAttributes?: Object
  ) {
    SMXAnswers.logContentView(
      contentName,
      contentType,
      contentId,
      customAttributes
    )
  },

  logInvite: function(method: string, customAttributes?: Object) {
    SMXAnswers.logInvite(method, customAttributes)
  },

  logLevelStart: function(levelName: string, customAttributes?: Object) {
    SMXAnswers.logLevelStart(levelName, customAttributes)
  },

  logLevelEnd: function(
    levelName: string,
    score: number,
    success: boolean,
    customAttributes?: Object
  ) {
    SMXAnswers.logLevelEnd(
      levelName,
      getAsStringOrNull(score),
      success,
      customAttributes
    )
  },

  logLogin: function(
    method: string,
    success: boolean,
    customAttributes?: Object
  ) {
    SMXAnswers.logLogin(method, success, customAttributes)
  },

  logPurchase: function(
    itemPrice: number,
    currency: string,
    success: boolean,
    itemName: string,
    itemType: string,
    itemId: string,
    customAttributes?: Object
  ) {
    SMXAnswers.logPurchase(
      getAsStringOrNull(itemPrice),
      currency,
      success,
      itemName,
      itemType,
      itemId,
      customAttributes
    )
  },

  logRating: function(
    rating: number,
    contentId: string,
    contentType: string,
    contentName: string,
    customAttributes?: Object
  ) {
    SMXAnswers.logRating(
      getAsStringOrNull(rating),
      contentId,
      contentType,
      contentName,
      customAttributes
    )
  },

  logSearch: function(query: string, customAttributes?: Object) {
    SMXAnswers.logSearch(query, customAttributes)
  },

  logShare: function(
    method: string,
    contentName: string,
    contentType: string,
    contentId: string,
    customAttributes?: Object
  ) {
    SMXAnswers.logShare(
      method,
      contentName,
      contentType,
      contentId,
      customAttributes
    )
  },

  logSignUp: function(
    method: string,
    success: boolean,
    customAttributes?: Object
  ) {
    SMXAnswers.logSignUp(method, success, customAttributes)
  },

  logStartCheckout: function(
    totalPrice: number,
    count: number,
    currency: string,
    customAttributes?: Object
  ) {
    SMXAnswers.logStartCheckout(
      getAsStringOrNull(totalPrice),
      getAsStringOrNull(count),
      currency,
      customAttributes
    )
  },
}
