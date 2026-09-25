class Twitter:
    """
    create a graph modeling follows
    - a follow is a directed edge from a follower to a followee
    - map of sets (average O(1) follow/unfollow)
    maintain a queue of posts for each user, add new posts to the end of the queue with a global logical clock
    - O(1) post
    """

    def __init__(self):
        self.following = defaultdict(set)
        self.posts = defaultdict(list)
        self.clock = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posts[userId].append((-self.clock, tweetId, userId))
        self.clock += 1

    def getNewsFeed(self, userId: int) -> list[int]:
        user_following = self.following[userId]
        user_following.add(userId)
        num_following = len(user_following)
        post_ptr = {u: len(self.posts[u]) - 1 for u in user_following}
        news_feed = []

        heap = []
        for f_user in user_following:
            if post_ptr[f_user] >= 0:
                heap.append(self.posts[f_user][post_ptr[f_user]])
                post_ptr[f_user] -= 1
        heapq.heapify(heap)
        for i in range(10):
            if len(heap) == 0:
                break
            tweet = heapq.heappop(heap)
            news_feed.append(tweet[1])
            tweet_author = tweet[2]
            if post_ptr[tweet_author] >= 0:
                heapq.heappush(heap, self.posts[tweet_author][post_ptr[tweet_author]])
                post_ptr[tweet_author] -= 1

        return news_feed

    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].discard(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
