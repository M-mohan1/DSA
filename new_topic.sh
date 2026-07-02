#!/bin/bash

# Check if a topic name was provided
if [ -z "$1" ]; then
  echo "⚠️ Usage: ./new_topic.sh <Topic-Name>"
  echo "💡 Example: ./new_topic.sh Sliding-Window"
  exit 1
fi

TOPIC=$1
BASE_DIR="Algorithms/$TOPIC"

# 1. Create the main directory for the topic
mkdir -p "$BASE_DIR"

# 2. Generate the README.md template
cat <<EOF > "$BASE_DIR/README.md"
# $TOPIC

## The Core Concept
*Brief explanation in your own words.*

## Time & Space Complexity
* **Time:** O(?)
* **Space:** O(?)

## Identifying the Pattern
*How do I know to use this in a contest?* 
* 
* 
EOF

echo "✅ Successfully generated setup for: $TOPIC"
echo "📁 Check the folder at: $BASE_DIR/"