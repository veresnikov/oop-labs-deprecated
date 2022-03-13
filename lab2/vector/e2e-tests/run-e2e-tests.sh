#!/usr/bin/env bash

EXECUTABLE=$1
TEST_DIR=$2
TEST_RESULT_DIR="$TEST_DIR/result"

createDir() {
  mkdir "$1"
}

cleanupDir() {
  rm -r "$1"
}

exitWithCleanup() {
  cleanupDir "$2"
  exit "$1"
}
createDir "$TEST_RESULT_DIR"

echo "Run e2e tests for $EXECUTABLE"

TEST_FILES_COUNT=$(find "$TEST_DIR" -name "*-input" | wc -l)
for ((i = 1; i <= "$TEST_FILES_COUNT"; i++)) do
    echo "Running $i test of $TEST_FILES_COUNT"
    INPUT_FILE=$(find "$TEST_DIR" -name "$i-*-input")
    EXPECTED_FILE=$(find "$TEST_DIR" -name "$i-*-output")
    "$EXECUTABLE" < "$INPUT_FILE" > "$TEST_RESULT_DIR/$i-test-result"
    DIFF=$(diff "$EXPECTED_FILE" "$TEST_RESULT_DIR/$i-test-result")
    if [[ "$DIFF" != "" ]]; then
        echo "Error: $DIFF"
        exitWithCleanup 1 "$TEST_RESULT_DIR"
    fi
done

echo "All tests passed"
exitWithCleanup 0 "$TEST_RESULT_DIR"