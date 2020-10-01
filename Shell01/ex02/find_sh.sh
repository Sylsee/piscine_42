#!/bin/sh
find . -type f -name "*.sh" | sed 's/...$//' | grep -o '[^/]*$'
