#!/bin/bash

nohup python communications_main.py &
disown
echo starting communications