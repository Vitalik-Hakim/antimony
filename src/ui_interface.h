// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_UI_INTERFACE_H
#define BITCOIN_UI_INTERFACE_H

#include <string>

#include "util.h" // for int64

#include <boost/signals2/signal.hpp>

#include <boost/signals2/last_value.hpp>

class CBasicKeyStore;
class CWallet;
class uint256;

/** General change type (added, updated, removed). */
enum ChangeType {
    CT_NEW,
    CT_UPDATED,
    CT_DELETED
};

/** Signals for UI communication. */
class CClientUIInterface {
    public:
        /** Flags for CClientUIInterface::ThreadSafeMessageBox */
        enum MessageBoxFlags {
            ICON_INFORMATION = 0,
                ICON_WARNING = (1 U << 0),
                ICON_ERROR = (1 U << 1),
                /**
                 * Mask of all available icons in CClientUIInterface::MessageBoxFlags
                 * This needs to be updated, when icons are changed there!
                 */
                ICON_MASK = (ICON_INFORMATION | ICON_WARNING | ICON_ERROR),

                /** These values are taken from qmessagebox.h "enum StandardButton" to be directly usable */
                BTN_OK = 0x00000400 U, // QMessageBox::Ok
                BTN_YES = 0x00004000 U, // QMessageBox::Yes
                BTN_NO = 0x00010000 U, // QMessageBox::No
                BTN_ABORT = 0x00040000 U, // QMessageBox::Abort
                BTN_RETRY = 0x00080000 U, // QMessageBox::Retry
                BTN_IGNORE = 0x00100000 U, // QMessageBox::Ignore
                BTN_CLOSE = 0x00200000 U, // QMessageBox::Close
                BTN_CANCEL = 0x00400000 U, // QMessageBox::Cancel
                BTN_DISCARD = 0x00800000 U, // QMessageBox::Discard
                BTN_HELP = 0x01000000 U, // QMessageBox::Help
                BTN_APPLY = 0x02000000 U, // QMessageBox::Apply
                BTN_RESET = 0x04000000 U, // QMessageBox::Reset
                /**
                 * Mask of all available buttons in CClientUIInterface::MessageBoxFlags
                 * This needs to be updated, when buttons are changed there!
                 */
                BTN_MASK = (BTN_OK | BTN_YES | BTN_NO | BTN_ABORT | BTN_RETRY | BTN_IGNORE |
                    BTN_CLOSE | BTN_CANCEL | BTN_DISCARD | BTN_HELP | BTN_APPLY | BTN_RESET),

                /** Force blocking, modal message box dialog (not just OS notification) */
                MODAL = 0x10000000 U,

                /** Predefined combinations for certain default usage cases */
                MSG_INFORMATION = ICON_INFORMATION,
                MSG_WARNING = (ICON_WARNING | BTN_OK | MODAL),
                MSG_ERROR = (ICON_ERROR | BTN_OK | MODAL)
        };

    /** Show message box. */
    boost::signals2::signal < bool(const std::string & message,
        const std::string & caption, unsigned int style), boost::signals2::last_value < bool > > ThreadSafeMessageBox;

    /** Ask the user whether they want to pay a fee or not. */
    boost::signals2::signal < bool(int64 nFeeRequired), boost::signals2::last_value < bool > > ThreadSafeAskFee;

    /** Handle a URL passed at the command line. */
    boost::signals2::signal < void(const std::string & strURI) > ThreadSafeHandleURI;

    /** Progress message during initialization. */
    boost::signals2::signal < void(const std::string & message) > InitMessage;

    /** Translate a message to the native language of the user. */
    boost::signals2::signal < std::string(const char * psz) > Translate;

    /** Block chain changed. */
    boost::signals2::signal < void() > NotifyBlocksChanged;

    /** Number of network connections changed. */
    boost::signals2::signal < void(int newNumConnections) > NotifyNumConnectionsChanged;

    /**
     * New, updated or cancelled alert.
     * @note called with lock cs_mapAlerts held.
     */
    boost::signals2::signal < void(const uint256 & hash, ChangeType status) > NotifyAlertChanged;
};

extern CClientUIInterface uiInterface;

/**
 * Translation function: Call Translate signal on UI interface, which returns a boost::optional result.
 * If no translation slot is registered, nothing is returned, and simply return the input.
 */
inline std::string _(const char * psz) {
    boost::optional < std::string > rv = uiInterface.Translate(psz);
    return rv ? ( * rv) : psz;
}

#endif