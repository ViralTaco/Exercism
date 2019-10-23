import re # regex

def abbreviate(words):
    """
    This method takes in a string `words` and returns an acronym for it
    """
    words = words.replace('\'', '')
    return ''.join(re.findall('[A-Z]', words.title()))

