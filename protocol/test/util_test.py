from hypothesis import given, strategy, assume
from hypothesis.specifiers import integers_in_range, integers_from
from hypothesis.searchstrategy.strings import BinaryStringStrategy
from nose.tools import nottest
import hypothesis.strategytests as st

from test.strategies import *

import src.util as util

@given(BoundedInt)
def test_pack_inverts_unpack_str(i):
    assert util.unpack(str(util.pack(i.n, i.upper_bound))) == i.n

@given(str)
def test_unpack_inverts_pack(string):
    assert util.pack(util.unpack(string), len(string)) == string



