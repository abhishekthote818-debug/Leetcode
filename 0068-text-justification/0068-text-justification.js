var fullJustify = function(words, maxWidth) {
    let ans = [];
    let i = 0;

    while (i < words.length) {
        let j = i;
        let lineLength = 0;

        // Find words that fit in this line
        while (
            j < words.length &&
            lineLength + words[j].length + (j - i) <= maxWidth
        ) {
            lineLength += words[j].length;
            j++;
        }

        let wordCount = j - i;
        let spaces = maxWidth - lineLength;
        let line = "";

        // Last line OR only one word
        if (j === words.length || wordCount === 1) {
            for (let k = i; k < j; k++) {
                if (k > i) line += " ";
                line += words[k];
            }

            line += " ".repeat(maxWidth - line.length);
        } 
        else {
            let gaps = wordCount - 1;
            let eachSpace = Math.floor(spaces / gaps);
            let extraSpace = spaces % gaps;

            for (let k = i; k < j; k++) {
                line += words[k];

                if (k < j - 1) {
                    let count = eachSpace;

                    if (k - i < extraSpace) {
                        count++;
                    }

                    line += " ".repeat(count);
                }
            }
        }

        ans.push(line);
        i = j;
    }

    return ans;
};