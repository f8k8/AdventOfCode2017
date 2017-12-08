// Import the readline module
const Readline = require('readline');

// Create the readline interface
const readlineInterface = Readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Get the input
readlineInterface.question('Please enter your captcha: ', (answer) => {
	
	// Trim any whitespace
	answer = answer.trim();
	
	// Make sure only numbers were input
	// Here we use a regular expression to match any characters
	// that aren't digits
	if(answer.match(/[^0-9]/)) {
		console.log('Please enter only numbers.');
	}
	else {
		// Use the spread operator (...) to split the string into
		// and array
		let digits = [...answer];
		
		// Convert each string into an actual number
		// This uses the unary plus operator, which converts
		// the string into a number
		digits = digits.map(x => +(x));
		
		// Now we can loop over our array and sum them up
		let sum = 0;
		let numDigits = digits.length;
		if(numDigits > 0) {
			for(let digitIndex = 0; digitIndex < numDigits; ++digitIndex) {
				if(digits[digitIndex] === digits[(digitIndex + 1) % numDigits]) {
					sum += digits[digitIndex];
				}
			}
		}
		
		// Output our result
		console.log(`Your answer is ${sum}`);
	}		
	
	// Close the interface
	readlineInterface.close();
});