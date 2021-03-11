# Matomo SDK for React Native

This document describes how to get started using the Matomo Tracking SDK for React Native.
[Matomo](https://matomo.org/) is the leading open source web analytics platform
that gives you valuable insights into your website's visitors,
your marketing campaigns and much more, so you can optimize your strategy and experience of your visitors.
This relies on the native [Android SDK](https://github.com/matomo-org/matomo-sdk-android) and on the native [iOS SDK ](https://github.com/matomo-org/matomo-sdk-ios) for Matomo and this README page is heavily inspired by it.

## Getting started

Integrating Matomo into your React Native app

1.  [Install Matomo](https://matomo.org/docs/installation/)
2.  [Create a new website in the Matomo web interface](https://matomo.org/docs/manage-websites/). Copy the Website ID from "Settings > Websites".
3.  [Include the library](#include-the-library)
4.  [Initialize Tracker](#init-tracker).
5.  [Track screen views, goals and more](#tracker-usage).
6.  [Mocking](#mocking).

### Include the library

1. Link this repo in your `package.json` file.

`"react-native-matomo": "https://github.com/selfapy/react-native-matomo"`

2. Create a `react-native-config.js` file and disable autolinking by adding this

```javascript
module.exports = {
  dependencies: {
    'react-native-matomo': {
      platforms: {
        ios: null, // this will disable autolinking for this package on iOS
      },
    },
  },
};

```

#### iOS

#### iOS (with cocoapods)
`pod 'BNFMatomo', :podspec => '../node_modules/react-native-matomo/BNFMatomo.podspec'`

#### iOS (Manual)

1.  Add `node_modules/react-native-matomo/ios/BNFMatomo.xcodeproj` to your xcode project, usually under the `Libraries` group
2.  Add `libBNFMatomo.a` (from `Products` under `BNFMatomo.xcodeproj`) to build target's `Linked Frameworks and Libraries` and `Target Dependencies` lists
3. If the MatomoTracker is the first Swift library in your project you need to add a random .swift file to your project
4. In your main target set the Swift version to 4.2

#### Android

- Open `/android/settings.gradle`
- Below `include ':app'` add:

```
include ':react-native-matomo'
project(':react-native-matomo').projectDir = new File(rootProject.projectDir, '../node_modules/react-native-matomo/android/')
```

- Open `android/app/build.gradle`
- Add the following under `dependencies`:

```
implementation project(":react-native-matomo")
```

- Open your `MainApplication.java` file under `android/src`
- Import the lib using `import de.bonify.reactnativematomo.MatomoPackage;`
- Add the following `new MatomoPackage()` to the `getPackages` function.

### Tracker Usage

#### Init tracker

Before using any function below, the tracker must be initialized.

```javascript
Matomo.initTracker('https://your-matomo-domain.tld/piwik.php', 1);
```

#### Set User ID

Providing the tracker with a user ID lets you connect data collected from multiple devices and multiple browsers for the same user. A user ID is typically a non empty string such as username, email address or UUID that uniquely identifies the user. The User ID must be the same for a given user across all her devices and browsers. .
If user ID is used, it must be persisted locally by the app and set directly on the tracker each time the app is started.

If no user ID is used, the SDK will generate, manage and persist a random id for you.

```javascript
Matomo.setUserId('123e4567-e89b-12d3-a456-426655440000');
```

#### Custom Dimensions

The Matomo SDK currently supports Custom Dimensions for the Visit Scope. Using Custom Dimensions you can add properties to the whole visit, such as "Did the user finish the tutorial?", "Is the user a paying user?" or "Which version of the Application is being used?" and such. Before sending custom dimensions please make sure Custom Dimensions are [properly installed and documented](https://matomo.org/docs/custom-dimensions/). You will need the ID of your configured Dimension.

After that you can set a new Dimension,

```javascript
Matomo.setCustomDimension(1, 'abc');
```

or remove an already set dimension.

```javascript
Matomo.setCustomDimension(1, null);
```
Dimensions in the Visit Scope will be sent along every Page View or Event. Custom Dimensions are not persisted by the SDK and have to be re-configured upon application startup.

#### Track screen views

To send a screen view set the screen path and titles on the tracker.

```javascript
Matomo.trackScreen('/your_activity', 'Title');
```

#### Track events

To collect data about user's interaction with interactive components of your app, like button presses or the use of a particular item in a game
use trackEvent.

```javascript
Matomo.trackEvent('category', 'action', 'label', 1000);
```

#### Track goals

If you want to trigger a conversion manually or track some user interaction simply call the method trackGoal. Read more about what is a [Goal in Matomo](http://matomo.org/docs/tracking-goals-web-analytics/).

```javascript
Matomo.trackGoal(1, revenue);
```

#### Track App Downloads

If you want to track the app downloads, there is also a function to do that (only supported on Android).

```javascript
Matomo.trackAppDownload();
```

#### Setting App Opt Out

The MatomoTracker SDK supports opting out of tracking. Note that this flag must be set each time the app starts up and will default to false. To set the app-level opt out, use:

```javascript
Matomo.setAppOptOut(true);
```

### Mocking

Add this line in your jest `setupFiles` configuration option from `package.json`

```
  "setupFiles": [
    ...
    "./node_modules/react-native-matomo/jest.setup.js"
  ],
```


## Contribute

- Fork the project
- Create a feature branch based on the 'master' branch
- Create a PR and feel proud.

## License

react-native-matomo is released under the MIT license, see [LICENSE](https://github.com/BonifyByForteil/react-native-matomo/blob/master/LICENSE).
