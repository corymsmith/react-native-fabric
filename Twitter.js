/**
 * @providesModule Twitter
 */
'use strict';

var { NativeModules } = require('react-native');
var SMXTwitter = NativeModules.SMXTwitter;

module.exports = {
  login: function (cb) {
    SMXTwitter.login(cb);
  },
  logOut: function () {
    SMXTwitter.logOut();
  },
  composeTweet: function (options, cb) {
    SMXTwitter.composeTweet(options, cb);
  }
};
