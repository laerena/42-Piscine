int	issep(char c, char *charset);
int	count_w(char *str, char *charset);
int	w_len(char *str, char *charset, int start);
char	*extract_w(char *str, int start, int len);

char	**ft_split(char *str, char *charset)
{
	// Count words (substrings between separators)
	// Allocate array of char* (word_count + 1 for NULL)
	// For each word:
	//   - Find start and end
	//   - Allocate memory for that word
	//   - Copy the word
	// Set last element to NULL
}
