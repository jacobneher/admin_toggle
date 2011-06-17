(function ($) {
  Drupal.behaviors.quickbar = {
  attach: function (context, settings) {
    $('.admin-toggle-admin-tabs').click(function() {
      if ($(this).hasClass('active')) {
        $(this).removeClass('active');
        $('div.tabs').css('display', 'none');
      }
      else {
        $(this).addClass('active');
        $('div.tabs').css('display', 'block');
      }
    });
    
    $('.admin-toggle-messages').click(function() {
      if ($(this).hasClass('active')) {
        $(this).removeClass('active');
        $('div.messages').css('display', 'none');
      }
      else {
        $(this).addClass('active');
        $('div.messages').css('display', 'block');
      }
    });
  }
  }
})(jQuery);