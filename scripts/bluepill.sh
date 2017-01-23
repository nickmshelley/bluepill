# //  Copyright 2016 LinkedIn Corporation
# //  Licensed under the BSD 2-Clause License (the "License");
# //  you may not use this file except in compliance with the License.
# //  You may obtain a copy of the License at https://opensource.org/licenses/BSD-2-Clause
# //
# //  Unless required by applicable law or agreed to in writing, software
# //  distributed under the License is distributed on an "AS IS" BASIS,
# //  WITHOUT WARRANTIES OF ANY KIND, either express or implied.  See the License for the specific language governing permissions and limitations under the License.

#!/bin/bash

if [[ $# -ne 1 ]]; then
  echo $0: usage: bluepill.sh build OR bluepill.sh test
  exit 1
fi

bluepill_build()
{
  xcodebuild \
    -workspace Bluepill.xcworkspace \
    -scheme bluepill \
    -configuration Release \
    -derivedDataPath "build/"
}

bluepill_test()
{
  default_runtime=`grep BP_DEFAULT_RUNTIME ./Source/Shared/BPConstants.h | sed 's/.*BP_DEFAULT_RUNTIME *//;s/"//g;s/ *$//g;'`
  xcrun simctl list runtimes | grep -q "$default_runtime" || {
    echo "Your system doesn't contain latest runtime: iOS $default_runtime"
    exit -1
  }

  rm -rf build/
  set -ex

  NSUnbufferedIO=YES
  export NSUnbufferedIO

  BPBuildScript=YES
  export BPBuildScript

  mkdir -p build/

  xcodebuild build-for-testing \
    -workspace Bluepill.xcworkspace \
    -scheme BPSampleApp \
    -sdk iphonesimulator \
    -derivedDataPath "build/" || exit 1

  xcodebuild test \
    -workspace Bluepill.xcworkspace \
    -scheme BPInstanceTests \
    -derivedDataPath "build/" 2>&1 | tee result.txt

  if ! grep '\*\* TEST SUCCEEDED \*\*' result.txt; then
    echo 'Test failed'
    echo See result.txt for details
    exit 1
  fi

  xcodebuild test \
    -workspace Bluepill.xcworkspace \
    -scheme BluepillRunnerTests \
    -derivedDataPath "build/" 2>&1 | tee result.txt

  # work around BPSampleTests failure fails the Bluepill tests.

  if ! grep '\*\* TEST SUCCEEDED \*\*' result.txt; then
    echo 'Test failed'
    echo See results.txt for details
    exit 1
  fi

  bluepill_build

  test $? == 0 || {
          echo Build failed
          exit 1
  }
  test -x build/Build/Products/Release/bluepill || {
          echo No bp built
          exit 1
  }
}

if [[ $1 == "build" ]]; then
  bluepill_build
elif [[ $1 == "test" ]]; then
  bluepill_test
else
  echo Unrecognized argument $1, please use build or test as argument
  exit 1
fi

exit 0
