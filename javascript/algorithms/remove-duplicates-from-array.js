let nums = [1, 1, 1, 1, 2, 2, 5, 7, 8, 5, 7, 8];
let out = [];

for (let i = 0; i < nums.length; i++) {
  let j = 0;
  let exists = false;
  do {
    if (out[j] === nums[i]) {
      exists = true;
      break;
    }
    j++;
  } while (j < out.length);

  if (!exists) out.push(nums[i]);
}

console.log(out);
