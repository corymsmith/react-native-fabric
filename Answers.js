/**
 * @providesModule Answers
 */
'use strict';

var { NativeModules } = require('react-native');
var SMXAnswers = NativeModules.SMXAnswers;

module.exports = {
  logCustom: function (eventName:string, customAttributes) {
    SMXAnswers.logCustom(eventName, customAttributes);
  },
  logAddToCart: function (itemPrice:number, currency:string, itemName:string, itemType:string, itemId:string, customAttributes) {
    SMXAnswers.logAddToCart(getAsStringOrNull(itemPrice), currency, itemName, itemType, itemId, customAttributes);
  },

  logContentView: function (contentName:string, contentType:string, contentId:string, customAttributes) {
    SMXAnswers.logContentView(contentName, contentType, contentId, customAttributes);
  },

  logInvite: function (method:string, customAttributes) {
    SMXAnswers.logInvite(method, customAttributes);
  },

  logLevelStart: function (levelName:string, customAttributes) {
    SMXAnswers.logLevelStart(levelName, customAttributes);
  },

  logLevelEnd: function (levelName:string, score:number, success:boolean, customAttributes) {
    SMXAnswers.logLevelEnd(levelName, getAsStringOrNull(score), success, customAttributes);
  },

  logLogin: function (method:string, success:boolean, customAttributes) {
    SMXAnswers.logLogin(method, success, customAttributes);
  },

  logPurchase: function (itemPrice:number, currency:string, success:boolean, itemName:string, itemType:string, itemId:string, customAttributes) {
    SMXAnswers.logPurchase(getAsStringOrNull(itemPrice), currency, success, itemName, itemType, itemId, customAttributes);
  },

  logRating: function (rating:number, contentId:string, contentType:string, contentName:string, customAttributes) {
    SMXAnswers.logRating(getAsStringOrNull(rating), contentId, contentType, contentName, customAttributes);
  },

  logSearch: function (query:string, customAttributes) {
    SMXAnswers.logSearch(query, customAttributes);
  },

  logShare: function (method:string, contentName:string, contentType:string, contentId:string, customAttributes) {
    SMXAnswers.logShare(method, contentName, contentType, contentId, customAttributes);
  },

  logSignUp: function (method:string, success:boolean, customAttributes) {
    SMXAnswers.logSignUp(method, success, customAttributes);
  },

  logStartCheckout: function (totalPrice:number, count:number, currency:string, customAttributes) {
    SMXAnswers.logStartCheckout(getAsStringOrNull(totalPrice), getAsStringOrNull(count), currency, customAttributes);
  }
};

function getAsStringOrNull(value:number) {
  if (value == null)
    return value;
  return value + "";
}


