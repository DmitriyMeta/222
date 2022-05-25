echo "Running tests..."
echo

req_val=${1:-0} 
shift 1

output=$(./main $@)


if [ $? -eq $(((256+$req_val)%256)) ] ; then
  echo "Pass: Program exited $req_val"
else
  echo "Fail: Program did not exit $req_val"
  exit 1
fi

echo "Tests passed."

exit 0
