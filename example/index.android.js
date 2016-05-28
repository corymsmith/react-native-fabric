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
  View,
  Image
} from 'react-native';

import {Crashlytics, Twitter} from 'react-native-fabric'

class example extends Component {
  constructor(props) {
    super(props);

    this.state = {
      user: null
    }
  }

  loginAndFetchProfile() {
    Twitter.login((loginError, loginResult) => {
      console.log(loginError);
      console.log(loginResult);

      Twitter.fetchProfile((e, result) => {
        console.log(e);
        console.log(result);
        const user = result;
        this.setState({user});
      });

    });
  }

  logout() {
    Twitter.logout();
    const user = null;
    this.setState({user});
  }


  render() {
    return (
      <View style={styles.container}>
        {this.state.user && <View>
          <Image style={styles.background} source={{uri: this.state.user.profile_background_image_url}}/>
          <View style={{alignItems: 'center', justifyContent: 'center'}}>
            <Image style={styles.avatar} source={{uri: this.state.user.profile_image_url}}/>
            <Text style={styles.username}>{this.state.user.screen_name}</Text>
            <Text style={styles.name}>{this.state.user.name}</Text>
            <Text style={styles.description}>{this.state.user.description}</Text>
          </View>
        </View>
        }
        {this.state.user && <Text style={styles.logoutButton}
                                  onPress={this.logout.bind(this)}>Logout</Text>}

        {!this.state.user && <Text style={styles.loginButton}
                                   onPress={this.loginAndFetchProfile.bind(this)}>Log in with Twitter</Text>}
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#ffffff',
    padding: 30
  },
  avatar: {
    width: 50,
    height: 50,
    borderRadius: 25
  },
  name: {
    fontSize: 20,
    textAlign: 'center',
    fontWeight: '600'
  },
  username: {
    textAlign: 'center',
    color: '#333333',
  },
  description: {
    marginVertical: 20,
    fontSize: 16,
    fontWeight: '200',
    textAlign: 'center',
  },
  logoutButton: {
    fontSize: 16,
    fontWeight: '500',
    textAlign: 'center',
    backgroundColor: '#acacac',
    color: 'white',
    paddingVertical: 10,
    paddingHorizontal: 20,
    borderRadius: 5,
    margin: 10
  },
  loginButton: {
    fontSize: 16,
    fontWeight: '500',
    textAlign: 'center',
    backgroundColor: '#4099ff',
    color: 'white',
    paddingVertical: 10,
    paddingHorizontal: 20,
    borderRadius: 5,
    margin: 10
  }
});

AppRegistry.registerComponent('example', () => example);
