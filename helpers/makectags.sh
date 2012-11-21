#!/bin/sh

cd ../src
ctags --no-members -t -T -I color.cpp color.hpp cprocessing.cpp cprocessing.hpp extfuncs.cpp lights.cpp pnoise.cpp pnoise.hpp primitives.cpp pvector.hpp shapes.cpp snoise.cpp snoise.hpp style.cpp style.hpp transformations.cpp
mv tags ../helpers
echo "done"
