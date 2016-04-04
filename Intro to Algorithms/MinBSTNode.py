class MinBSTNode(BSTNode):
    """A node in BST which is augmented to keep track of the node with the minimum key
    in the subtree rooted at this node.
    """
    def __init__(self, parent, key):
        super(MinBSTNode, self).__init__(parent, key)
        self.min = selfs

    def insert(self, node):
        """Inserts a node into the subtree rooted at this node.

        Args:
            node: The node to be inserted.
        """
        if node is None:
            return 
        if node.key < self.key:
            # Updates the min of this node if the inserted node has a smaller
            # key.
            if node.key < self.min.key:
                self.min = node
            if self.left is None:
                node.parent = self
                self.left = node
            else:
                self.left.insert(node)
        else:
            if self.right is None:
                node.parent = self
                self.right = node
            else:
                self.right.insert(node)

    def delete(self):
        """Deletes and returns this node from the BST."""
        if self.left is None or self.right is None:
            if self is self.parent.left:
                self.parent.left = self.left or self.right  # assigns the existing
                                                            # subtree of self to 
                                                            # self.parent.left
                # Case: 1
                if self.parent.left is not None:
                    self.parent.left.parent = self.parent
                    self.parent.min = self.parent.left.min  # New line
                # Case: 2
            else:
                self.parent.min = self.parent
            # Propagates the changes upwards.
            current = self.parent
            while current.parent is not None and current is current.parent.left:
                current.parent.min = current.min
                current = current.parent
            else:
                self.parent.right = self.left or self.right
                if self.parent.right is not None:
                    self.parent.right.parent = self.parent
            return self
        else:
            s = self.next_larger()
            self.key, s.key = s.key, self.key   # swap the value with its successor
            return s.delete()