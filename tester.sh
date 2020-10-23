#!/bin/bash
function confirm() {
  local response msg="${1:-Are you sure} (y/[n])? "; shift
  read -r $* -p "$msg" response || echo
  case "$response" in
  [yY][eE][sS]|[yY]) return 0 ;;
  *) return 1 ;;
  esac
}

if [ $# -ne 3 ]
then
	echo "How to Use) \$sh hw1_tester.sh [path/of/binary/to/test]"
	exit 1;
fi
INPUTS=$(ls -1 $1/*\.in)
TOEXEC=$(ls -1 $2/*\.c)
TARGETDIR=$3
TOTAL=0
ANSWER=0
rm -f $3/*.result $3/*output $3/score.txt
for cfile in $TOEXEC
do
    Score=0
    trimmedUser=$(echo $cfile | sed 's/\.c//' | xargs -n1 basename)
    echo "Scoring $trimmedUser"
    gcc $cfile
    if [ $? -ne 0 ]
    then
        echo "Compile error! on $cfile"
        echo "$trimmedUser  Compile error" >> $3/score.txt
        continue
    fi
    cnt=0
    for input in $INPUTS
    do
        cnt=`expr $cnt + 1`
	    #trimmed=$(echo $input | sed 's/\./-/' | sed 's/-in//')
	    trimmed=$(echo $input | sed 's/\.in//' | xargs -n1 basename)
	    echo -n "Running test: $trimmed ... "
	    $(timeout 3s ./a.out < $input > $3/$trimmedUser.$trimmed.output)
	    diff -Bbi $1/$trimmed.out $3/$trimmedUser.$trimmed.output >> $3/$trimmedUser.$trimmed.result
	    if [ $? -eq 0 ]
	    then
	    	echo "pass"
	    	Score=`expr $Score + 1`
            rm $3/$trimmedUser.$trimmed.result
        else
		    echo "fail"
            echo "Input is"
            cat $input
            echo ""
            echo "Answer is"
            cat $1/$trimmed.out
            echo ""
            echo "Output is"
            cat $3/$trimmedUser.$trimmed.output
            echo ""
            confirm "Is it right?" && Score=`expr $Score + 1` && rm $3/$trimmedUser.$trimmed.result
        fi
        rm $3/$trimmedUser.$trimmed.output
    done
    echo "$trimmedUser  $Score / $cnt" >> $3/score.txt
done
