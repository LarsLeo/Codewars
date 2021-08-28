pub fn spin_words(words: &str) -> String {
    return words
        .split_whitespace()
        .map(|word| {
            return if word.len() < 5 {
                word.to_string()
            } else {
                word.chars().rev().collect()
            };
        })
        .collect::<Vec<String>>()
        .join(" ");
}
