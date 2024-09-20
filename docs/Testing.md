# Aixt Project Test Plan

- To help uniformity, quality, and reliability in the development of the Aixt project itself with the support of microcontroller-based systems, the "test" folder is added.

- This folder contains two types of tests: smoke tests and functional tests. Below is an explanation of what each folder contains and how to use the test suites within them.

## Smoke Test Folder

The smoke test folder includes tests that provide a quick check to ensure the basic functionality of the code is working correctly. These tests are not exhaustive but are designed to catch critical issues early.

#### Purpose: 
To verify the essential features and basic functionalities of the application.

#### How to Use: 
Simply follow the test suite within this folder to ensure that the primary functions of the code are operating as expected. This is usually done after a new build or an update to make sure that the main features have not been broken.

## Functional Test Folder

The functional test folder contains more comprehensive tests that validate the complete functionality of the code against the requirements. These tests are more detailed and ensure that the code behaves as expected under various conditions.

#### Purpose: 
To validate that the code works according to the specified requirements and performs all intended functions correctly.

#### How to Use: 
Follow the test suite within this folder to conduct thorough testing of the code's features. This includes testing individual functions, integrations, and workflows to ensure everything operates smoothly as expected.

**Note:** *All Smoke test cases must pass before running the Functional test cases.*