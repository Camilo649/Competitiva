#!/bin/bash

# You may use this scritp to test your srategy.
# If you store the data under path/to/data then you can run
# ./run.sh --pnl path/to/data
# To see the full output, remove '--pnl'

pnl=false; [[ $1 == --pnl ]] && pnl=true && shift

for f in "$1"/*; do
  echo "Running ${f}"
  if $pnl; then
    ./sim.exe < "$f" 2> /dev/null
  else
    ./sim.exe < "$f"
  fi
  echo ""
done
