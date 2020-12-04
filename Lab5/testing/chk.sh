for i in {1..100}
do
    sleep 1
    ./data 10000 100000 >in.in
    ./main <in.in >out.out
    ./dij <in.in >outt.out
    if ! diff out.out outt.out
    then
        break
    fi
    echo "Correct"
done
