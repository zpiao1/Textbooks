class BST(object):
    def __init__(self):
        self.root = None

    def find(self, k):
        return self.root and self.root.find(k)  # evaluates self.root first
                                                # if self.root is None, then return None
                                                # else, evaluate self.root.find(k) and then
                                                # return self.root.find(k)
    def find_min(self):
        """Returns the minimum node of this BST."""
        return self.root and self.root.find_min()

    def insert(self, k):
        node = BSTNode(None, k)
        if self.root is None:
            # The root's parent is None already.
            self.root = node
        else:
            self.root.insert(node)

    def delete(self, k):
        """Deletes and returns a node with key k if it exists from the BST.

        Args:
            k: The key of the node that we want to delete.
        """
        node = self.find(k)
        if node is None:
            return None
        if node is self.root:
            pseudoroot = BSTNode(None, 0)
            pseudoroot.left = self.root
            self.root.parent = pseudoroot
            deleted = self.root.delete()
            self.root = pseudoroot.left
            if self.root is not None:
                self.root.parent = None
            return deleted
        else:
            return node.delete()

        def next_larger(self, k):
            """Returns the node that contains the next larget (the successor) key
            in the BST in relation to the node with key k.

            Args:
                k: The key of the node of which the successor is to be found.

            Returns:
                The successor node.
            """
            node = self.find(k)
            return node and node.next_larger()
