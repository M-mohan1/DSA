#!/bin/bash

# Check if a topic name was provided
if [ -z "$1" ]; then
  echo "⚠️ Usage: ./new_topic.sh <Topic-Name>"
  echo "💡 Example: ./new_topic.sh Sliding-Window"
  exit 1
fi

TOPIC=$1
BASE_DIR="Algorithms/$TOPIC"

# 1. Create the main directory and Curated-Problems subfolder
mkdir -p "$BASE_DIR/Curated-Problems"

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

## Curated "Must-Do" Problems
1. [Problem Name](link) - *Takeaway: What makes this problem special?*
2. [Problem Name](link) - *Takeaway:*
3. [Problem Name](link) - *Takeaway:*
EOF

# 3. Generate a fast I/O C++ boilerplate
cat <<EOF > "$BASE_DIR/standard_template.cpp"
#include <bits/stdc++.h>
using namespace std;

// Standard Template for $TOPIC

void solve() {
    // Implementation goes here
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
EOF

echo "✅ Successfully generated setup for: $TOPIC"
echo "📁 Check the folder at: $BASE_DIR/"