function toNumber(arr) {
  let x = arr.join("");
  
  return parseInt(x);
}

function palindrome(arr) {
  return arr.every((v, i, a) => {
    if (i >= a.length / 2) {
      return true;
    }
    else {
      return v == a[a.length - i - 1];
    }
  })
}

function backTracking(i, exponent, storage, parse) {
  for (let j = 0; j <= 9; ++j) {
    parse[i] = j;
    
    if (i < exponent) {
      backTracking(i + 1, exponent, storage, parse);
    } else {
      if (palindrome(parse)) {
        let x = toNumber(parse);
        
        if (x != 0) {
          storage.push(x);
        }
      }
    }
  }
}

function findReverseNumber(n) {
  if (n <= 9) {
    return n - 1;
  }
  
  let storage = [0];
    
  let exp = 0;
  let parse = [];
  while (storage.length <= n) {
    parse = [];
    for (let i = 0; i <= exp; ++i) {
      parse.push(null);
    }
    
    backTracking(0, exp, storage, parse);
    ++exp;
  }
    
  return storage[n - 1];
}