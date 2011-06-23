(function ($) {
  Drupal.behaviors.admin_toggle_admin = {
  attach: function (context, settings) {
    set_default_display('#edit-admin-toggle-show-admin-tabs', 1);
    
    $('#edit-admin-toggle-show-admin-tabs').change(function() {
      set_default_display($(this));
    });
  }
  }
  
  function set_default_display(elem, effect) {
    if($(elem).val() == 'yes') {
      $('.admin-toggle-default-display').slideDown('fast');
    }
    else {
      if (effect) {
        $('.admin-toggle-default-display').css('display', 'none');
      }
      else {
        $('.admin-toggle-default-display').slideUp('fast');
      }
    }
  }
})(jQuery);