#!/bin/bash

cd /home/priest/Desktop/archlab-handout/sim
misc/yas  sample_files/binary_search_template.ys
#misc/yas  sample_files/merge_template.ys

# Check the first argument
case "$1" in
    python)
        echo "Evaluating..."
        #python3 verifiers/binary_search_verifier.py yis sample_files/binary_search_template.ys
        python3 verifiers/merge_verifier.py yis sample_files/merge_template.ys
        
        ;;
    tcl)
		echo "Simulating..."
        cd /home/priest/Desktop/archlab-handout/sim/seq
        #./ssim ../sample_files/binary_search_template.yo -g
        ./ssim ../sample_files/merge_template.yo -g
        ;;
    *)
        # Default action or message
        echo "End of Assembly..."
        ;;
esac
