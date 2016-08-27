def count_open_tweets(tweets):
	return sum(1 for key in tweets.keys() if tweets[key] == 1)

if __name__ == "__main__":
	n,k = map(int,raw_input().split())
	tweets = {}
	for i in xrange(k):
		input_ = raw_input().split()
		if len(input_) == 1:
			click = input_[0]
		else:
			click = input_[0]
			tweet_number = input_[1]		
		if click == "CLOSEALL":			
			tweets = tweets.fromkeys(tweets,0)
		else:
			if tweet_number in tweets:
				tweets[tweet_number] = tweets[tweet_number] ^ 1
			else:
				tweets[tweet_number] = 1
		print count_open_tweets(tweets)
