/* License: MIT. See LICENSE in root directory. */

/**
 * \date 2020/06/29
 */

#include "../../inc/ensemble/linked-list.hpp"

namespace Ensemble
{

template<typename ItemType, typename FinderType>
DlList<ItemType, FinderType>::~DlList()
{
    RemoveAll();
}

template<typename ItemType, typename FinderType>
void DlList<ItemType, FinderType>::Remove(ItemType *pItem)
{
    if (pItem->mListNode.mpNext != nullptr)
    {
        pItem->mListNode.mpNext->mListNode.mpPrev = pItem->mListNode.mpPrev;
    }
    else
    {
        mpTail = pItem->mListNode.mpPrev;
    }
    if (pItem->mListNode.mpPrev != nullptr)
    {
        pItem->mListNode.mpPrev->mListNode.mpNext = pItem->mListNode.mpNext;
    }
    else
    {
        mpHead = pItem->mListNode.mpNext;
    }
}

template<typename T1, typename T2>
void DlList<T1, T2>::RemoveAll()
{
    for (auto pItem = mpHead; mpHead != nullptr; pItem = mpHead)
    {
        Remove(pItem);
    }

    mpTail = 0;
    mpHead = 0;
}

} // namespace Ensemble
