#include "UserphraseModel.h"
#include "ChewingUserphraseModel.h"

int UserphraseModel::rowCount(const QModelIndex &parent) const
{
    return userphrase_.size();
}

QVariant UserphraseModel::data(const QModelIndex &index, int role) const
{
    auto& current_userphrase = userphrase_[index.row()];

    switch (role) {
    case Qt::DisplayRole:
        return current_userphrase.display;
        break;
    case Qt::WhatsThisRole: // FIXME: Provide "What's This?"
        break;
    default:
        break;
    }

    return QVariant();
}

std::unique_ptr<UserphraseModel> UserphraseModelFactory(const char* path)
{
    // TODO: Create properly UserphraseMode for this file type.
    return std::unique_ptr<UserphraseModel>(new ChewingUserphraseModel(path));
}
