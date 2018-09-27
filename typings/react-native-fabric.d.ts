/**
* react-native-fabric.d.ts
*
* Type definition file for the react native fabric package
*/

declare module 'react-native-fabric' {
    interface Fabric {

        /**
         * API for interacting with the Crashlytics kit.
         *
         * https://docs.fabric.io/ios/crashlytics/index.html
         */        
        Crashlytics: {
            crash(): void;
            throwException(): void;
            recordError(error: string | number | Object): void;

            logException(value: string): void;
            log(message: string): void;
            setUserEmail(email: string): void;
            setUserIdentifier(userIdentifier: string): void;
            setUserName(userName: string): void;
            setBool(key: string, value: boolean): void;
            setNumber(key: string, value: number): void;
            setString(key: string, value: string): void;
            recordCustomExceptionName(name: string, reason: string, frameArray: Array<Object>): void;
        }  

        /**
         * API for interacting with the Answers kit.
         *
         * https://docs.fabric.io/ios/answers/index.html
         */
        Answers: {

            /**
             * Sends the Purchase tracking event.
             *
             * All parameters are optional.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#purchase
             *
             * @param itemPrice The item's amount in the currency specified.
             * @param currency The ISO4217 currency code.
             * @param success Was the purchase completed succesfully?
             * @param itemName The human-readable name for the item.
             * @param itemType The category the item falls under.
             * @param itemId A unique identifier used to track the item.
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logPurchase(itemPrice?: number, currency?: string, success?: boolean, itemName?: string, itemType?: string, itemId?: string, attributes?: Attributes): void;

            /**
             * Sends the Add To Cart tracking event.
             *
             * All parameters are optional.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#add-to-cart
             *
             * @param itemPrice The item's amount in the currency specified.
             * @param currency The ISO4217 currency code.
             * @param itemName The human-readable name for the item.
             * @param itemType The category the item falls under.
             * @param itemId A unique identifier used to track the item.
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logAddToCart(itemPrice?: number, currency?: string, itemName?: string, itemType?: string, itemId?: string, attributes?: Attributes): void;

            /**
             * Sends the Search tracking event.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#search
             *
             * @param query What the user is searching for.
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logSearch(query: string, attributes?: Attributes): void;

            /**
             * Sends the Share tracking event.
             *
             * All parameters are optional.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#share
             *
             * @param method The method used to share content.
             * @param contentName The description of the content.
             * @param contentType The type or genre of content.
             * @param contentId A unique key identifying the content.
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logShare(method?: string, contentName?: string, contentType?: string, contentId?: string, attributes?: Attributes): void;

            /**
             * Sends the Sign Up tracking event.
             *
             * All parameters are optional.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#sign-up
             *
             * @param method An optional description of the sign up method (Twitter, Facebook, etc.); defaults to "Direct".
             * @param success An optional flag that indicates sign up success; defaults to true.
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logSignUp(method?: string, success?: boolean, attributes?: Attributes): void;

            /**
             * Sends the Log In tracking event.
             *
             * All parameters are optional.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#log-in
             *
             * @param method An optional description of the sign in method (Twitter, Facebook, etc.); defaults to "Direct".
             * @param success An optional flag that indicates sign in success; defaults to true.
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logLogin(method?: string, success?: boolean, attributes?: Attributes): void;

            /**
             * Sends the Invite tracking event.
             *
             * All parameters are optional.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#invite
             *
             * @param method An optional description of the sign in method (Twitter, Facebook, etc.); defaults to "Direct".
             * @param attributes Any additional user-defined attributes to be logged.
             */
            logInvite(method?: string, attributes?: Attributes): void;
  
            /**
             * Send the Content View tracking event.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#content-view
             */
            logContentView(name: string, type?: string, id?: string, attributes?: Attributes): void;

            /**
             * Send a custom tracking event with the given name.
             *
             * https://docs.fabric.io/android/answers/answers-events.html#custom-event
             */
            logCustom(name: string, attributes?: Attributes): void;
        }       
    }

    /**
     * A key/value pair of strings.
     */
    interface Attributes {
        [index: string]: String;
    } 

    var Fabric: Fabric;
    export = Fabric;
}
