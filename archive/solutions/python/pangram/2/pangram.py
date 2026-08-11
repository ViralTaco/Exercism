def is_pangram(sentence: str) -> bool:
    """Return True if the given sentence contains every letter of the alphabet."""
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    for char in alphabet:
        if char not in sentence.lower():
            return False
    return True