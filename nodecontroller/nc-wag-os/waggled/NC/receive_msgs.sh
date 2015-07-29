#!/bin/bash

nohup python receive.py &
disown
echo Ready to receive messages