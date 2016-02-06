#Current Status
GPU Ocelot project is not longer actively maintained. The latest system requirement and installation guide are available at [https://github.com/gtcasl/gpuocelot/wiki/Installation](https://github.com/gtcasl/gpuocelot/wiki/Installation)


#Overview
Ocelot is a modular dynamic compilation framework for heterogeneous system, providing various backend targets for CUDA programs and analysis modules for the PTX virtual instruction set. **Ocelot currently allows CUDA programs to be executed on NVIDIA GPUs, AMD GPUs, and x86-CPUs at full speed without recompilation.** For more information, check [http://gpuocelot.gatech.edu/](http://gpuocelot.gatech.edu/).

#Installation
Please check the installation guide [here](https://github.com/gtcasl/gpuocelot/wiki/Installation).

#Resources
* Source code documentation
[http://gpuocelot.gatech.edu/doxygen](http://gpuocelot.gatech.edu/doxygen)
* Mailing list
[http://groups.google.com/group/gpuocelot](http://groups.google.com/group/gpuocelot)

#News
March, 2013 - Actively seeking developers for AMD and Intel GPU backends. Please post on the mailing list if interested.

June 10, 2012 - GPU Ocelot tutorial to be presented at ISCA 2012.

May 14, 2012 - GPU Ocelot poster to be presented at GPU Technology Conference.

March 5, 2012 - Call for developers for the NVIDIA GPU device and the AMD GPU device. Initial implementations are in-place but we could greatly benefit from owners willing to test the code and add new features as new hardware (Kepler, GCN) comes out. Post on the mailing list if you are interested.

October 10, 2011 - Ocelot tutorial at PACT 2011.

#Contributing
##Documentation
Ocelot currently is lacking good documentation for installation and common usage. If anyone is interested in writing tutorials or howtos please post on the mailing list.

##Complete a Feature Request
If you would like to contribute to this project and help with any of the directions on our roadmap you can do the following:

1. Pull a task from the list of issues
2. Implement it on your own
3. Post a patch to the relevant issue
  * See the [requirements](https://github.com/gtcasl/gpuocelot/wiki/ContributingRequirements) for contributing a feature
  * If it is accepted we will merge it into the main codebase
4. Ask us about becoming a registered developer

##Branch Our Code
If you want to work on something not on our roadmap, but want to host your code on this site, contact us about becoming a developer and creating a branch.

##Start A New Project
If you want to work independently using Ocelot as a starting point, feel free to copy our most current release and use it internally.

#Special Thanks
We would like to thank the following people, who have contributed novel ideas, software, and tests to the project:

* Nathan Bell
* Sylvain Collange
* David Luebke
* Diogo Sampaio
* Ryuta Suzuki
* Steve Worley
* Ignacio Llamas
* James Bigler
* Greg Humphreys
