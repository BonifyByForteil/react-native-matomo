jest.mock('react-native-matomo', () => ({
  initTracker: jest.fn(),
  setUserId: jest.fn(),
  setCustomDimension: jest.fn(),
  trackScreen: jest.fn(),
  trackEvent: jest.fn(),
  trackGoal: jest.fn(),
  trackAppDownload: jest.fn(),
  setAppOptOut: jest.fn()
}));
