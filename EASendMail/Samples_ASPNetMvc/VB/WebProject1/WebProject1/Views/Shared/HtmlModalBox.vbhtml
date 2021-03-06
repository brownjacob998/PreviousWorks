﻿
@Code
    Layout = Nothing
End Code

<!-- Modal Confirm -->
<div id="dialogbox_confirm" class="modal fade">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                <h4 class="modal-title"><span class="fa fa-warning fa-fw fa-2x" style="color:#ff0000; vertical-align: middle;"></span><span>Warning</span></h4>
            </div>
            <div class="modal-body">
                <p>Are you sure to do this operation?</p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
                <button type="button" class="btn btn-primary">Yes</button>
            </div>
        </div>
    </div>
</div>

<!-- Modal Alert -->
<div id="dialogbox_alert" class="modal fade">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                <h4 class="modal-title"><span class="fa fa-warning fa-fw fa-2x" style="color:#ff0000; vertical-align: middle;"></span><span>Warning</span></h4>
            </div>
            <div class="modal-body">
                <p>Are you sure to do this operation?</p>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-primary" data-dismiss="modal">OK</button>
            </div>
        </div>
    </div>
</div>

<!-- Modal Status -->
<div id="dialogbox_status" class="modal fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" data-backdrop="static" data-keyboard="false">
    <div class="modal-dialog modal-sm" role="document">
        <div class="modal-content">
            <div class="modal-body">
                <span class="fa fa-spinner fa-spin fa-fw fa-2x" style="color:#0099dd; vertical-align: middle;"></span>
                <span style="margin-left: 10px;" class="current-modal-status">Please wait ...</span>
            </div>
            <div class="current-body-status" style="padding: 10px;"></div>
        </div>
    </div>
</div>





