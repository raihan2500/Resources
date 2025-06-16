#!/bin/bash

PROJECT_DIR="/usr/include/x86_64-linux-gnu/algo"
VENV_DIR="$PROJECT_DIR/mytempvenv"

# ১. virtual environment তৈরি না থাকলে তৈরি করো
if [ ! -d "$VENV_DIR" ]; then
    echo "Creating virtual environment..."
    python3 -m venv "$VENV_DIR"
    source "$VENV_DIR/bin/activate"
    echo "Installing required packages..."
    pip install --upgrade pip
    pip install graphviz
else
    echo "Activating existing virtual environment..."
    source "$VENV_DIR/bin/activate"
fi

# ২. কোড চালাও
python3 "$PROJECT_DIR/visualizer.py"

# ৩. অপেক্ষা করো user input এর জন্য
echo "Press Enter to exit..."
read

