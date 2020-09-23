TreeRemove(tree, key) {
   par = 0
   cur = tree->root
   while (cur is not 0) // Search for node
      if (cur->key == key) // Node found 
         if (!cur->left && !cur->right)         // Remove leaf
            if (!par) // Node is root
               tree->root = 0;
            else if (par->left == cur) 
               par->left = 0
            else
               par->right = 0
         else if (cur->left && !cur->right)     // Remove node with only left child
            if (!par) // Node is root
               tree->root = cur->left
            else if (par->left == cur) 
               par->left = cur->left
            else
               par->right = cur->left
         else if (!cur->left && cur->right)     // Remove node with only right child
            if (!par) // Node is root
               tree->root = cur->right
            else if (par->left == cur) 
               par->left = cur->right
            else
               par->right = cur->right
         else                                   // Remove node with two children
            // Find successor (leftmost child of right subtree)
            suc = cur->right
            while (suc->left is not 0)
               suc = suc->left
            cur = Copy suc                       // Copy successor to current node
            TreeRemove(cur->right, suc->key)     // Remove successor from right subtree
         return // Node found and removed
      else if (cur->key < key) // Search right
         par = cur
         cur = cur->right
      else                     // Search left
         par = cur
         cur = cur->left
   return // Node not found
}
