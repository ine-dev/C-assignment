#!/bin/bash

yes | build/hexdump  hexdump-test-text.txt > textOutput.txt
yes | build/hexdump  hexdump-test-binary.png > binaryOutput.txt