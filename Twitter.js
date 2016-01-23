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
  logout: function () {
    SMXTwitter.logout();
  }
};
