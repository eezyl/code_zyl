
BINNAME   = test.exe
BINPATH   = ./
SRCPATH   = src/
EXE       = $(BINPATH)$(BINNAME)

CXX       = g++
CHDRS     = $(wildcard $(SRCPATH)*.hpp $(SRCPATH)*.h)
CSRCS     = $(wildcard $(SRCPATH)*.cpp)
COBJS     = $(addsuffix .o, $(basename $(CSRCS)))
#CINCLS	  = -I$(SRCPATH)util -I$(SRCPATH)router -I$(SRCPATH)circuit -Ilib -Llib/LEDA

CFLAGS    = -std=c++11 -O3 -Wall -fopenmp 
#CFLAGS    += -fopenmp
#CFLAGS    = -std=c++11 -g -Wall

ECHO      = echo
RM        = rm
MKDIR     = mkdir

$(EXE): $(COBJS)
	@$(MKDIR) -p $(BINPATH)
	@$(ECHO) "[Build Target] $(EXE)"
	@$(CXX) $(CFLAGS)  $(COBJS) -lm -o $(EXE) 

$(SRCPATH)%.o: $(SRCPATH)%.cpp $(CHDRS)
	@$(ECHO) "[Compile] $<"
	@$(CXX) $(CFLAGS) $(CINCLS) -c $< -o $@ 

clean:
	@$(RM) -rf $(EXE) $(COBJS)
