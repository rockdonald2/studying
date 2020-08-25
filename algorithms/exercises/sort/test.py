from unittest import main, TestCase
import types
from index import *

nonSorted = [100, -40, 500, -124, 0, 21, 7]
sorted = [-124, -40, 0, 7, 21, 100, 500]

class TestBubbleSort(TestCase):
    def test_fn(self):
        self.assertEqual(type(bubbleSort), types.FunctionType, 'BubbleSort isnt a function')
    
    def test_v(self):
        self.assertEqual(bubbleSort(nonSorted), sorted, 'BubbleSort isnt sorting correctly')

class TestSelectionSort(TestCase):
    def test_fn(self):
        self.assertEqual(type(selectionSort), types.FunctionType, 'SelectionSort isnt a function')
    
    def test_v(self):
        self.assertEqual(selectionSort(nonSorted), sorted, 'SelectionSort isnt sorting correctly')

class TestMergeSort(TestCase):
    def test_fn(self):
        self.assertEqual(type(mergeSort), types.FunctionType, 'MergeSort isnt a function')
        self.assertEqual(type(merge), types.FunctionType, 'Merge isnt a function')

    def test_m(self):
        self.assertEqual(merge([1, 10], [2, 8, 12]), [1, 2, 8, 10, 12], 'Merge isnt merging correctly')
    
    def test_v(self):
        self.assertEqual(mergeSort(nonSorted), sorted, 'MergeSort isnt sorting correctly')

if __name__ == '__main__':
    main()