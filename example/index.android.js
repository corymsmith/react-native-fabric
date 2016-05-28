/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 */
'use strict';
import React, {
  AppRegistry,
  Component,
  StyleSheet,
  Text,
  View
} from 'react-native';

import {Crashlytics, Twitter} from 'react-native-fabric'

class example extends Component {
  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.button} onPress={ e => {
                   Twitter.login((e, result) => {
                     console.log(e);
                     console.log(result);
                   });
        }}>
          Login to Twitter
        </Text>
        <Text style={styles.button} onPress={ e => {
                   Twitter.fetchProfile((e, result) => {
                     console.log(e);
                     console.log(result);
                   });
        }}>
          Fetch Profile
        </Text>

      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#F5FCFF',
  },
  button: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5,
  },
});

AppRegistry.registerComponent('example', () => example);
